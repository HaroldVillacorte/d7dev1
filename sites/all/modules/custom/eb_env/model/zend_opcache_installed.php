<?php
/**
* @file
* Checks if the opcache.so file is installed onthe machine.
*/

namespace eb_env\model;

require_once 'parent_class.php';

class zend_opcache_installed extends \eb_env\model\parent_class
{

    public function __construct()
    {
        parent::__construct(t('Zend OPCache'));
        
        // Set result.
        if (function_exists('opcache_get_status') && function_exists('(opcache_get_configuration')) {
            $result_string = t('Zend OPCcache is not enabled.');
        }
        else {
            $opcache_config = opcache_get_configuration();
            $version = $opcache_config['version']['version'];
            $result_string = t('Zend OPCache version ') . $version . t(' is enbaled.');
        }
        //var_dump(opcache_get_status());
        //var_dump(opcache_get_configuration());
        $this->set_result($result_string);
        
        // Set links.
        $this->set_links(array(
            'OPcache' => 'http://www.php.net/manual/en/book.opcache.php',
        ));
        
        // Set description.
        $this->set_description(t(file_get_contents($this->text_dir . 'description/zend_opcache_installation.txt')));
    }

}
