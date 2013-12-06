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
        // Intialize the result string.
        $result_string = '';
        
        // Get the $databases array.
        global $databases;
        
        // Initialize the result array.
        $result_array = array(
            'Smart Ip module' => (module_exists('smart_ip')) ? 'Installed' : 'Not installed',
            'Smart Ip version' => (defined('EB_SMART_IP_VERSION')) ? EB_SMART_IP_VERSION : 'Stock',
            'Is geo_ip database in settings.php?' => ($databases['geo_ip']) ? 'Yes' : 'No',
        );
        
        // Check geo_ip database is readable.
        if ($databases['geo_ip']) {
            db_set_active('geo_ip');
            try {
                $result = db_query('SELECT geoip_id, ip_ref, country_code, region,
                    city, zip, latitude, longitude FROM {smart_ip} LIMIT 1');
                $result_array['Is geo_ip database readable?'] = 'Yes, it is readable';
                //var_dump($result->fetchAssoc());
            }
            catch (\Exception $e) {
                $result_array['Is geo_ip database readable?'] = 'No, it is not readable';
            }
            db_set_active('default');
        }
        
        // Get the Smart Ip session.
        if (smart_ip_session_get('smart_ip')) {
            $smart_ip_session = smart_ip_session_get('smart_ip');
            foreach ($smart_ip_session['location'] as $key => $value) {
                $result_array['[Smart Ip session]: ' . $key] = $value;
            }        
        }
        
        // Parse $result_array to $result_string as table rows.
        foreach ($result_array as $key => $value) {
            $result_string .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value . '</td>' .
                '</tr>';
        }
        
        // Parse the template with $result_string.
        $text_file = t(file_get_contents($this->text_dir . 'result/smart_ip.phtml'));
        $result = str_replace('<% result %>', $result_string, $text_file);
        
        // Run the result setter.
        $this->set_result($result);
        
        // Set links.
        $this->set_links(array(
            t('Drupal.org: Smart Ip') => 'https://drupal.org/project/smart_ip',
        ));
        
        // Set description.    
        $this->set_description(t(file_get_contents($this->text_dir . 'description/smart_ip.phtml')));
    }

}
