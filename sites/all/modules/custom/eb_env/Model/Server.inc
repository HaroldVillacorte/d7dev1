<?php
/**
* @file
* Gets certain server settings.
*/

namespace eb_env\Model;

require_once 'ParentClass.inc';

/**
* The Server model.
*/
class Server extends \eb_env\Model\ParentClass
{

    /**
    * The Server contructor
    */
    public function __construct()
    {
        parent::__construct(t('Server'));


        // Set result.
        // Intialize the result string.
        $resultString = '';

        // Initialize the result array.
        $resultArray = array(
            'Server Software' => $_SERVER['SERVER_SOFTWARE'],
            'Server name' => $_SERVER['SERVER_NAME'],
            'Server ip address' => $_SERVER['SERVER_ADDR'],
            'Php version' => phpversion(),
            'php.ini loaded file' => php_ini_loaded_file(),
            'Php memory' => ini_get('memory_limit'),
            'APC enabled' => (ini_get('apc.enabled') && extension_loaded('apc')) ? 'True' : 'False',
        );

        // Parse $resultArray to $resultString as table rows.
        foreach ($resultArray as $key => $value) {
            $resultString .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value . '</td>' .
                '</tr>';
        }

        // Parse the template with $resultString.
        $textFile = t(file_get_contents($this->viewDir . 'result/server.phtml'));
        $result = str_replace('<% result %>', $resultString, $textFile);

        // Run the result setter.
        $this->setResult($result);

        // Set links.
        $this->setLinks(array(
            t('Affecting PHP\'s Behaviour ') => 'http://us3.php.net/manual/en/refs.basic.php.php',
            t('Drupal.org: Increase PHP memory limit') => 'https://drupal.org/node/207036',
        ));

        // Set description.
        $string = t(file_get_contents($this->viewDir . 'description/server.phtml'));
        $this->setDescription($string);

        //var_dump($_SERVER);
    }

}
