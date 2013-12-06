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
                'current' => 'none',
            ),
            'opcache.memory_consumption' => array(
                'recommended' => '128',
                'current' => 'none',
            ),
            'opcache.interned_strings_buffer' => array(
                'recommended' => '8',
                'current' => 'none',
            ),
            'opcache.max_accelerated_files' => array(
                'recommended' => '4000',
                'current' => 'none',
            ),
            'opcache.revalidate_freq' => array(
                'recommended' => '60',
                'current' => 'none',
            ),
            'opcache.fast_shutdown' => array(
                'recommended' => '1',
                'current' => 'none',
            ),
            'opcache.enable_cli' => array(
                'recommended' => '1',
                'current' => 'none',
            ),
        );
        
        // Set result.
        if (!function_exists('opcache_get_status') && !function_exists('opcache_get_configuration')) {
            $result_array['Zend OPCache Installed']['current'] = t('Zend OPCcache is not enabled.');
        }
        else {// Zend OPCache is installed.
        
            // Get the Zend OPCache settings.
            $opcache_config = opcache_get_configuration();
            $version = $opcache_config['version']['version'];
            $directives = $opcache_config['directives'];
            
            // Result: installed with version.
            $result_array['Zend OPCache Installed']['current'] = t('Zend OPCache version ') . $version . t(' is enbaled.');
            
            // Result: opcache.memory_consumption
            $result_array['opcache.memory_consumption']['current'] = $directives['opcache.memory_consumption']/1024/1024;
            
            // Result: opcache.interned_strings_buffer
            $result_array['opcache.interned_strings_buffer']['current'] = $directives['opcache.interned_strings_buffer'];
            
            // Result: opcache.max_accelerated_files
            $result_array['opcache.max_accelerated_files']['current'] = $directives['opcache.max_accelerated_files'];
            
            // Result: opcache.revalidate_freq
            $result_array['opcache.revalidate_freq']['current'] = $directives['opcache.revalidate_freq'];
            
            // Result: opcache.fast_shutdown
            $result_array['opcache.fast_shutdown']['current'] = ($directives['opcache.fast_shutdown']) ?
                '1' : '0';
                
            // Result: opcache.enable_cli 
            $result_array['opcache.enable_cli']['current'] = ($directives['opcache.enable_cli']) ?
                '1' : '0';
                
            //var_dump(opcache_get_status());
            //var_dump(opcache_get_configuration());
        }
        
        // Parse $result_array to $result_string as table rows.
        foreach ($result_array as $key => $value) {
            $result_string .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value['current'] . '</td>' .
                '<td>' . $value['recommended'] . '</td>' .
                '</tr>';
        }
        
        // Parse the template with $result_string.
        $text_file = t(file_get_contents($this->text_dir . 'result/zend_opcache_installation.phtml'));
        $result = str_replace('<% result %>', $result_string, $text_file);
        
        // Run the result setter.
        $this->set_result($result);
        
        // Set links.
        $this->set_links(array(
            'OPcache' => 'http://www.php.net/manual/en/book.opcache.php',
        ));
        
        // Set description.
        $this->set_description(t(file_get_contents($this->text_dir . 'description/zend_opcache_installation.phtml')));
    }

}
