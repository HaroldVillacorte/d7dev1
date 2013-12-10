<?php
/**
* @file
* Generates Home page markup.
*/

namespace eb_proquery\Controller;

require_once 'ParentController.inc';

/**
* The Home page class.
*/
class HomeController extends ParentController
{

    /**
    * The Home page contructor.
    * @param string $title The Home page title.
    * @param array $data The data array.
    */
    public function __construct($title = 'Title not set.', $data)
    {
        parent::__construct($title);

        // Set the view.
        $this->setView('home.phtml');

        // Set the title variable.
        $this->data['title'] = $this->getTitle();

        // Set the All Professions with Associated Topics url variable.
        $this->data['all_url'] = $this->baseUrl . '/admin/eb/proquery/all/0';

        // Initialize the body string.
        $body = '';

        // Parse the data to body string.
        foreach ($data as $value) {
            $path = $value->tid . '-' . str_replace(' ', '_', $value->name);
            $body .= '<a href="' . $this->baseUrl . '/admin/eb/proquery/' . $path . '/0">' . $value->name . '</a>' . '&nbsp;&nbsp;||&nbsp;&nbsp;';
        }

        // Add body to data array property.
        $this->data['body'] = $body;

        // Set markup.
        $this->setMarkup($this->data);
    }

}
