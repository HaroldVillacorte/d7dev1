<?php
/**
* @file
* Checks if the opcache.so file is installed onthe machine.
*/

namespace eb_env\Model;

require_once 'ParentClass.inc';

/**
* The ZendOpcache model.
*/
class ZendOpcache extends \eb_env\Model\ParentClass
{

    public function __construct()
    {
        parent::__construct(t('Zend OPCache'));

        // Intialize the $resultString.
        $resultString = '';

        // Initialize the $resultArray.
        $resultArray = array(
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
            $resultArray['Zend OPCache Installed']['current'] = t('Zend OPCcache is not enabled.');
        }
        elseif (function_exists('opcache_get_status') && function_exists('opcache_get_configuration')) {// Zend OPCache is installed.

            // Get the Zend OPCache settings.
            $opcacheConfig = opcache_get_configuration();
            $version = $opcacheConfig['version']['version'];
            $directives = $opcacheConfig['directives'];

            // Result: installed with version.
            $resultArray['Zend OPCache Installed']['current'] = t('Zend OPCache version ') . $version . t(' is enbaled.');

            // Result: opcache.memory_consumption
            $resultArray['opcache.memory_consumption']['current'] = $directives['opcache.memory_consumption']/1024/1024;

            // Result: opcache.interned_strings_buffer
            $resultArray['opcache.interned_strings_buffer']['current'] = $directives['opcache.interned_strings_buffer'];

            // Result: opcache.max_accelerated_files
            $resultArray['opcache.max_accelerated_files']['current'] = $directives['opcache.max_accelerated_files'];

            // Result: opcache.revalidate_freq
            $resultArray['opcache.revalidate_freq']['current'] = $directives['opcache.revalidate_freq'];

            // Result: opcache.fast_shutdown
            $resultArray['opcache.fast_shutdown']['current'] = ($directives['opcache.fast_shutdown']) ?
                '1' : '0';

            // Result: opcache.enable_cli
            $resultArray['opcache.enable_cli']['current'] = ($directives['opcache.enable_cli']) ?
                '1' : '0';

            //var_dump(opcache_get_status());
            //var_dump(opcache_get_configuration());
        }

        // Parse $resultArray to $resultString as table rows.
        foreach ($resultArray as $key => $value) {
            $resultString .=
                '<tr>' .
                '<td>' . $key . '</td>' .
                '<td>' . $value['current'] . '</td>' .
                '<td>' . $value['recommended'] . '</td>' .
                '</tr>';
        }

        // Parse the template with $resultString.
        $textFile = t(file_get_contents($this->viewDir . 'result/zend_opcache.phtml'));
        $result = str_replace('<% result %>', $resultString, $textFile);

        // Run the result setter.
        $this->setResult($result);

        // Set links.
        $this->setLinks(array(
            'OPcache' => 'http://www.php.net/manual/en/book.opcache.php',
        ));

        // Set description.
        $this->setDescription(t(file_get_contents($this->viewDir . 'description/zend_opcache.phtml')));
    }

}
