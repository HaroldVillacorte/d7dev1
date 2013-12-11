<?php
/**
* @file
* Gets profession related data from the database.
*/

namespace libraries\expertbeacon\Model\Data;

/**
* The eb_proquery Profession model class.
*/
class Profession
{

    /**
    * Databse query gets all profession terms.
    * @return function db_query
    */
    public function  getAll()
    {
        //db_set_active('expertbeacon');
        $result = db_query('SELECT tid, name FROM {taxonomy_term_data} WHERE vid = :vid', array(':vid' => 4));
        return $result;
        //db_set_active('default');
    }

    /**
    * Database query get profession matching like name returning json.
    * @param string $name The name of the profession.
    * @return json Json object.
    */
    public function getByNameJson($name = '')
    {
        //db_set_active('expertbeacon');
        $result = db_query('SELECT name FROM {taxonomy_term_data} WHERE name LIKE :name LIMIT 15', array(':name' => '%' . db_like($name) . '%'));
        $matches = array();
        foreach($result as $item) {
        $matches[$item->name] = check_plain($item->name);
        }
        drupal_json_output($matches);
        //db_set_active('default');
        drupal_exit();
    }

}
