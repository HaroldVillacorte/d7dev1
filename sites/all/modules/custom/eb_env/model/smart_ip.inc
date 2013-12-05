<?php
/**
* @file
* Checks that Drupal Smart Ip module version 7.2.2 is installed.
*/

namespace eb_env\model;

require_once 'parent_class.inc';

/**
* The smart_ip class.
*/
class smart_ip extends \eb_env\model\parent_class
{
    
    /**
    * The php_memory constructor.
    */
    public function __construct()
    {
        parent::__construct(t('Smart Ip'));
        
        // Set result.
        //$module_list = module_list();
        $result = (module_exists('smart_ip')) ? t('enabled.') : t('not enabled.');
        $this->set_result(t('Smart Ip is currently ') . $result);
        
        // Set links.
        $this->set_links(array(
            t('Drupal.org: Smart Ip') => 'https://drupal.org/project/smart_ip',
        ));
        
        // Set body.
        
        $desc_array = array();
        
        // Check for the geo_ip database in the settings.php file.
        global $databases;
        $str_pass = 'geo_ip database is in the settings.php file.';
        $str_fail = 'geo_ip database is in the settings.php file.';      
        $desc_array['Databases'] = ($databases['geo_ip']) ? $str_pass : $str_fail;
        
        $smart_ip_session = smart_ip_session_get('smart_ip');
        $description = '';
        if ($smart_ip_session['location']) {
            foreach ($smart_ip_session['location'] as $key => $value) {
                $description .= $key . ' = ' . $value . '<br/>';
            }
        }
        //var_dump($smart_ip_session);        
        $this->set_description($description);
    }

}
