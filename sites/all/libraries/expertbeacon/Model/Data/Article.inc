<?php
/**
* @file
* Gets article related data from the database.
*/

namespace libraries\expertbeacon\Model\Data;

/**
* The eb_proquery Article model class.
*/
class Article
{

    /**
    * Database query gets count of articles related to a topic.
    * @param int $tid The term id of the Content field from the rlated topic node.
    * @return function db_query
    */
    public function getCountByTopic($tid = null)
    {
        //db_set_active('expertbeacon');
        $query = 'SELECT COUNT(vocabulary_3.taxonomy_vocabulary_3_tid) AS count
                    FROM {field_data_taxonomy_vocabulary_3} AS vocabulary_3
                    WHERE vocabulary_3.taxonomy_vocabulary_3_tid = :tid';
        $result = db_query($query, array(':tid' => (int) $tid));
        return $result;
        //db_set_active('default');
    }

}
