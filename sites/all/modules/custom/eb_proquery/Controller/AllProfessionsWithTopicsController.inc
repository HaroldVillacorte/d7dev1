<?php
/**
* @file
* Generates Markup for all Professions with Topics.
*/

namespace eb_proquery\Controller;

require_once 'ParentController.inc';

/**
* The AllProfessionsWithTopics Controller.
*/
class AllProfessionsWithTopicsController extends ParentController
{

    /**
    * The AllProfessionsWithTopicsController contructor.
    * @param string $title The Home page title.
    * @param array $data The data array.
    */
    public function __construct($title = 'Title not set.', $data)
    {
        // Parse the $title.
        $title_parsed = ucwords(str_replace('_', ' ', $title));

        // Parent constructor.
        parent::__construct($title_parsed);

        // Set the view.
        $this->setView('all_professions_with_topics.phtml');

        // Set the title variable.
        $this->data['title'] = $this->getTitle();

        // Set the urls variables.
        $this->data['back_url'] = $this->baseUrl . '/admin/eb/proquery';
        $this->data['csv_url'] = $this->baseUrl . '/admin/eb/proquery/' . $title . '/1';

        // Initialize the table head and table body strings.
        $thead = '';
        $tbody = '';

        // Initalize the $topic_count array.
        $topic_count = array();

        // Get the topics counts for each profession as an array.
        foreach ($data as $value) {
            $topic_count[] = count($value->topics);
        }

        // Generate the $thead content from the max($topic_count).
        for ($i = 0; $i < max($topic_count) + 1; $i++) {
            $thead .= '<th>' . $i . '</th>';
        }

        // Parse the data to body string.
        foreach ($data as $value) {
            $tbody .= '<tr>';
            $tbody .=     '<td>' . $value->name . '</td>';
                for ($i = 0; $i < max($topic_count); $i++) {
                    if ($i < count($value->topics)) {
                        $tbody .= '<td>' . $value->topics[$i]->name . '</td>';
                    }
                    else {
                        $tbody .= '<td></td>';
                    }
                }
            $tbody .=  '</tr>';
        }

        // Add body to data array property.
        $this->data['thead'] = $thead;
        $this->data['tbody'] = $tbody;

        // Set markup.
        $this->setMarkup($this->data);
    }

    /**
    * Csv download for eb_proquery_topics_by_profession_page() with case
    * all_professions_with_associated_topics.
    * @param array $data The data array to convert to csv.
    * @return file $csv Returns a csv file.
    */
    public function getCsv($data = array())
    {
        // Set headers.
        header("Cache-Control: public");
        header("Content-Type: application/octet-stream");
        header("Cache-Control: no-store, no-cache, must-revalidate");
        header("Cache-Control: post-check=0, pre-check=0");
        header("Content-Disposition: attachment; filename=\"all_professions_with_associated_topics.csv\";" );
        header("Content-Transfer-Encoding: binary");

        // Initialize csv string.
        $csv = '';

        // Initalize the $topic_count array.
        $topic_count = array();

        // Get the topics counts for each profession as an array.
        foreach ($data as $value) {
            $topic_count[] = count($value->topics);
        }

        // Parse the data to $csv string.
        foreach ($data as $row) {
            $csv .=  '"' . $row->name . '",';
                for ($i = 0; $i < max($topic_count); $i++) {
                    if ($i < count($row->topics) - 1 && $i < max($topic_count) -1) {
                        $csv .= '"' . $row->topics[$i]->name . '",';
                    }
                    elseif ($i == count($row->topics) -1 && $i < max($topic_count) -1) {
                        $csv .= '"' . $row->topics[$i]->name . '",';
                    }
                    elseif ($i == count($row->topics) -1 && $i == max($topic_count) -1) {
                        $csv .= '"' . $row->topics[$i]->name . '"';
                    }
                    elseif ($i > count($row->topics) -1 && $i < max($topic_count) -1) {
                        $csv .= '"",';
                    }
                    elseif ($i > count($row->topics) -1 && $i == max($topic_count) -1) {
                        $csv .= '""';
                    }
                    else {
                        $csv .= '';
                    }
                }
            $csv .= '
';
        }

        // Return csv file.
        echo($csv);

        // Exit the script.
        drupal_exit();
    }

}
