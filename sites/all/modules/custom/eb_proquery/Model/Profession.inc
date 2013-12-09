<?php
/**
* @file
* Gets profession related data from the database.
*/

namespace eb_proquery\Model;

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
        // db_set_active('expertbeacon');
        $result = db_query('SELECT tid, name FROM taxonomy_term_data WHERE vid = :vid', array(':vid' => 4));
        return $result;
        // db_set_active('default');
    }

}
