<?php
/**
* @file
* Gets topic related data from the database.
*/

namespace libraries\expertbeacon\Model\Data;

/**
* The eb_proquery Topic model class.
*/
class Topic
{

    /**
    * Databse query gets all ptopics by Profession.
    * @param int $tid The profession term id.
    * @return function db_query
    */
    public function getByProfession($tid = null)
    {
        //db_set_active('expertbeacon');
        $query = 'SELECT :tid AS profession_id,
                profession.entity_id AS topic_id,
                topic_node.title AS topic_title,
                field_content.field_content_tid AS content_id,
                term.name AS name
            FROM {field_data_field_customer_type} profession
                INNER JOIN {node} topic_node ON profession.entity_id = topic_node.nid
                LEFT OUTER JOIN {field_data_field_content} field_content ON field_content.entity_id = topic_node.nid
                LEFT OUTER JOIN {taxonomy_term_data} term ON field_content.field_content_tid = term.tid
            WHERE profession.field_customer_type_tid = :tid';
        $result = db_query($query, array(':tid' => (int) $tid));
        return $result;
        //db_set_active('default');
    }

}
