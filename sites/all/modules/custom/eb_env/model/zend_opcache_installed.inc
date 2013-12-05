<?php
/**
* @file
* Checks if the opcache.so file is installed onthe machine.
*/

namespace eb_env\model;

require_once 'parent_class.inc';

class zend_opcache_installed extends \eb_env\model\parent_class
{

    public function __construct()
    {
        parent::__construct(t('Zend OPCache'));
        
        // Intialize the result string.
        $result_string = '';
        
        // Initialize the result array.
        $result_array = array(
            'Zend OPCache Installed' => array(
                'recommended' => 'Install Zend OPCache',
            ),
        );
        
        // Set result.
        if (!function_exists('opcache_get_status') && function_exists('opcache_get_configuration')) {
            $result_array['Zend OPCache Installed']['current'] = t('Zend OPCcache is not enabled.');
        }
        else {
            $opcache_config = opcache_get_configuration();
            $version = $opcache_config['version']['version'];
            $result_array['Zend OPCache Installed']['current'] = t('Zend OPCache version ') . $version . t(' is enbaled.');
        }
        
        foreach ($result_array as $key => $value) {
            $result_string =
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value['current'] . '</td>' .
                '<td>' . $value['recommended'] . '</td>' .
                '</tr>';
        }
        
        
        //var_dump(opcache_get_status());
        var_dump(opcache_get_configuration());
        
        $text_file = t(file_get_contents($this->text_dir . 'result/zend_opcache_installation.txt'));
        $result = str_replace('{{result}}', $result_string, $text_file);
        
        // Run the result setter.
        $this->set_result($result);
        
        // Set links.
        $this->set_links(array(
            'OPcache' => 'http://www.php.net/manual/en/book.opcache.php',
        ));
        
        // Set description.
        $this->set_description(t(file_get_contents($this->text_dir . 'description/zend_opcache_installation.txt')));
    }

}
