<?php
/**
* @file
* The Place model class.
*/

namespace libraries\expertbeacon\Model\Data;

/**
* The Place model.
*/
class Place
{

    /**
    * Database query to find places by name returning json object.
    * @param string $place The name of the place.
    * @return json A json object.
    */
    public function getByNameJson($place = '')
    {
        //db_set_active('expertbeacon');
        $result = db_query('SELECT title FROM {node} WHERE title LIKE :place LIMIT 15', array(':place' => '%' . db_like($place) . '%'));
        $matches = array();
        foreach($result as $item) {
        $matches[$item->title] = check_plain($item->title);
        }
        drupal_json_output($matches);
        //db_set_active('default');
        drupal_exit();
    }

}
