<?php
/**
* @file
* Checks that Drupal Smart Ip module version 7.2.2 is installed.
*/

namespace eb_env\Model;

require_once 'ParentClass.inc';

/**
* The SmartIp model.
*/
class SmartIp extends \eb_env\Model\ParentClass
{

    /**
    * The SmartIp constructor.
    */
    public function __construct()
    {
        parent::__construct(t('Smart Ip'));

        // Set result.
        // Intialize the $resultString.
        $resultString = '';

        // Get the $databases array.
        global $databases;

        // Initialize the $resultArray.
        $resultArray = array(
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
                $resultArray['Is geo_ip database readable?'] = 'Yes, it is readable';
                //var_dump($result->fetchAssoc());
            }
            catch (\Exception $e) {
                $resultArray['Is geo_ip database readable?'] = 'No, it is not readable';
            }
            db_set_active('default');
        }

        // Get the Smart Ip session.
        if (smart_ip_session_get('smart_ip')) {
            $smartIpSession = smart_ip_session_get('smart_ip');
            foreach ($smartIpSession['location'] as $key => $value) {
                $resultArray['[Smart Ip session]: ' . $key] = $value;
            }
        }

        // Parse $resultArray to $resultString as table rows.
        foreach ($resultArray as $key => $value) {
            $resultString .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value . '</td>' .
                '</tr>';
        }

        // Parse the template with $resultString.
        $textFile = t(file_get_contents($this->viewDir . 'result/smart_ip.phtml'));
        $result = str_replace('<% result %>', $resultString, $textFile);

        // Run the result setter.
        $this->setResult($result);

        // Set links.
        $this->setLinks(array(
            t('Drupal.org: Smart Ip') => 'https://drupal.org/project/smart_ip',
        ));

        // Set description.
        $this->setDescription(t(file_get_contents($this->viewDir . 'description/smart_ip.phtml')));
    }

}
