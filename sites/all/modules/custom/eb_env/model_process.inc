<?php
/**
* @file
* Gets the model classes and generates the output array.
*/

namespace eb_env;

require_once 'model/php_ini_location.inc';
require_once 'model/php_memory.inc';
require_once 'model/zend_opcache_installed.inc';
require_once 'model/smart_ip.inc';

class model_process
{

    /**
    * Genreates the output array.
    */
    public function get_output()
    {
        // Instatiate the child model classes.
        $php_ini_location = new \eb_env\model\php_ini_location();
        $php_memory = new \eb_env\model\php_memory();
        $zend_opcache_installed = new \eb_env\model\zend_opcache_installed();
        $smart_ip = new \eb_env\model\smart_ip();

        // Generate the output array and return.
        return array(
        
            // php_ini_location
            array(
                'title' => $php_ini_location->get_title(),
                'result' => $php_ini_location->get_result(),
                'links' => $php_ini_location->get_links(),
                'description' => $php_ini_location->get_description(),
            ),
        
            // php_memory
            array(
                'title' => $php_memory->get_title(),
                'result' => $php_memory->get_result(),
                'links' => $php_memory->get_links(),
                'description' => $php_memory->get_description(),
            ),
            
            // zend_opcache_installed
            array(
                'title' => $zend_opcache_installed->get_title(),
                'result' => $zend_opcache_installed->get_result(),
                'links' => $zend_opcache_installed->get_links(),
                'description' => $zend_opcache_installed->get_description(),
            ),
            
            // smart_ip
            array(
                'title' => $smart_ip->get_title(),
                'result' => $smart_ip->get_result(),
                'links' => $smart_ip->get_links(),
                'description' => $smart_ip->get_description(),
            ),
        );
    }

}

