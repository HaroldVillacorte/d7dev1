<?php
/**
* @file
* Generates Topics by Profession page markup.
*/

namespace eb_proquery\Controller;

require_once 'ParentController.inc';

/**
* The TopicsByProfession Controller.
*/
class TopicsByProfessionController extends ParentController
{

    /**
    * The TopicsByProfessionController contructor.
    * @param string $title The Home page title.
    * @param array $data The data array.
    * @param string $arg1 Used in the csv url.
    */
    public function __construct($title = 'Title not set.', $data, $arg1)
    {
        parent::__construct($title);

        // Set the view.
        $this->setView('topics_by_profession.phtml');

        // Set the title variable.
        $this->data['title'] = $this->getTitle();

        // Set the urls variables.
        $this->data['back_url'] = $this->baseUrl . '/admin/eb/proquery';
        $this->data['csv_url'] = $this->baseUrl . '/admin/eb/proquery/' . $arg1 . '/1';

        // Initialize the table body string.
        $tbody = '';

        // Parse the data to body string.
        // var_dump($data);
        foreach ($data as $value) {
            $tbody .= '<tr>'
                   .       '<td>' . $value->profession_id . '</td>'
                   .       '<td>' . $value->topic_id . '</td>'
                   .       '<td>' . $value->topic_title . '</td>'
                   .       '<td>' . $value->content_id . '</td>'
                   .       '<td>' . $value->name . '</td>'
                   .       '<td>' . $value->count . '</td>'
                   .  '</tr>';
        }

        // Add body to data array property.
        $this->data['tbody'] = $tbody;

        // Set markup.
        $this->setMarkup($this->data);
    }

    /**
    * Csv download for eb_proquery_topics_by_profession_page()
    * with case %.
    * @param string $title This will be included in the file name.
    * @param array $data The data array to convert to csv.
    * @return file $csv Returns a csv file.
    */
    public function getCsv($title = 'data', $data = array())
    {
        // Set headers.
        header("Cache-Control: public");
        header("Content-Type: application/octet-stream");
        header("Cache-Control: no-store, no-cache, must-revalidate");
        header("Cache-Control: post-check=0, pre-check=0");
        header("Content-Disposition: attachment; filename=\"profession-{$title}.csv\";" );
        header("Content-Transfer-Encoding: binary");

        // Initialize csv string.
        $csv = '';

        // Generate csv rows from data array.
        foreach ($data as $row) {
            $csv .= '"' . $row->profession_id . '",'
                 . '"' . $row->topic_id . '",'
                 . '"' . $row->topic_title . '",'
                 . '"' . $row->content_id . '",'
                 . '"' . $row->name . '",'
                 . '"' . $row->count . '"
';
        }

        // Return csv file.
        echo($csv);

        // Exit the script.
        drupal_exit();
    }

}
