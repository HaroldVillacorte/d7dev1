<?php
/**
* @file
* Finds the location of the php.ini file.
*/

namespace eb_env\model;

require_once 'parent_class.inc';

/**
* The php_ini_location class.
*/
class php_ini_location extends \eb_env\model\parent_class
{

    /**
    * The php_ini_location contructor
    */
    public function __construct()
    {
        parent::__construct(t('Server'));
        
        
        // Set result.
        // Intialize the result string.
        $result_string = '';
        
        // Initialize the result array.
        $result_array = array(
            'Server Software' => $_SERVER['SERVER_SOFTWARE'],
            'Server name' => $_SERVER['SERVER_NAME'],
            'Server ip address' => $_SERVER['SERVER_ADDR'],
            'Php version' => phpversion(),
            'php.ini loaded file' => php_ini_loaded_file(),
            'Php memory' => ini_get('memory_limit'),
            'APC enabled' => (ini_get('apc.enabled') && extension_loaded('apc')) ? 'True' : 'False',
        );
        
        // Parse $result_array to $result_string as table rows.
        foreach ($result_array as $key => $value) {
            $result_string .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value . '</td>' .
                '</tr>';
        }
        
        // Parse the template with $result_string.
        $text_file = t(file_get_contents($this->text_dir . 'result/server.phtml'));
        $result = str_replace('<% result %>', $result_string, $text_file);
        
        // Run the result setter.
        $this->set_result($result);
        
        // Set links.
        $this->set_links(array(
            t('Affecting PHP\'s Behaviour ') => 'http://us3.php.net/manual/en/refs.basic.php.php',
            t('Drupal.org: Increase PHP memory limit') => 'https://drupal.org/node/207036',
        ));
        
        // Set description.
        $string = t(file_get_contents($this->text_dir . 'description/server.phtml'));
        $this->set_description($string);
        
        //var_dump($_SERVER);
    }

}
