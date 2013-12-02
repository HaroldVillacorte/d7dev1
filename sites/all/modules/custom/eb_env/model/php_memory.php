<?php
/**
* @file
* Checks the memory allocation set in php options.
*/

namespace eb_env\model;

require_once 'parent_class.php';

/**
* The php_memory class.
*/
class php_memory extends \eb_env\model\parent_class
{
    
    /**
    * The php_memory constructor.
    */
    public function __construct()
    {
        parent::__construct(t('Php Memory'));
        
        // Set result.
        $ini_result = ini_get('memory_limit');
        $this->set_result(t('Php memory is currently set to') . ': ' . $ini_result);
        
        // Set links.
        $this->set_links(array(
            t('Drupal.org: Increase PHP memory limit') => 'https://drupal.org/node/207036',
        ));
        
        // Set body.
        $string = t(file_get_contents($this->text_dir . 'description/php_memory_description.txt'));
        $this->set_description($string);
    }

}
