<?php
/**
* @file
* Checks that Drupal Smart Ip module version 7.2.2 is installed.
*/

namespace eb_env\model;

require_once 'parent_class.php';

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
        //var_dump(module_list());
        $smart_ip_session = smart_ip_session_get('smart_ip');
        //var_dump($smart_ip_session);
        //var_dump($_SESSION['smart_ip']);
        $description = '';
        foreach ($smart_ip_session['location'] as $key => $value) {
            $description .= $key . ' = ' . $value . '<br/>';
        }
        $this->set_description(
            '<form class="form">
                <fieldset style="padding-left: 20px;">
                    <legend>Find Ip</legend>
                    <label for="country">Country</label>
                    <input type="text" placeholder="country" name="country" class="form-text">
                    <label for="region">Region</label>
                    <input type="text" placeholder="region" name="region" class="form-text">
                    <label for="zip">Zip</label>
                    <input type="text" placeholder="zip" name="zip" class="form-text">
                    <br/><br/>
                    <input type="submit" name="submit" value="Query" class="form-submit">
                </fieldset>
            </form>'
            . '<p>' . $description . '</p>'
        );
    }

}
