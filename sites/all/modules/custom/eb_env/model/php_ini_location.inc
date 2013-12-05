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
        parent::__construct(t('Php.ini File Location'));
        
        // Set result.
        $ini_loaded = php_ini_loaded_file();
        $result = ($ini_loaded) ? $ini_loaded : '<em>' . t('Unable to find the php.ini file.') . '</em>';
        $this->set_result($result);
        
        // Set links.
        $this->set_links(array(
            t('Affecting PHP\'s Behaviour ') => 'http://us3.php.net/manual/en/refs.basic.php.php',
        ));
        
        // Set description.
        $string = t(file_get_contents($this->text_dir . 'description/php_ini_location.txt'));
        $this->set_description($string);
    }

}
