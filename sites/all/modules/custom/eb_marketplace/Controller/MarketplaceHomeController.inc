<?php
/**
* @file
* Generates Marketplace Home Page.
*/

namespace eb_proquery\Controller;

require_once 'MarketplaceHomeController.inc';

/**
* The MarketplaceHome Controller.
*/
class MarketplaceHomeController extends ParentController
{

    /**
    * The MarketplaceHomeController constructor.
    * @param string $title The Home page title.
    */
    public function __construct($title = 'Title not set.')
    {
        parent::__construct($title);

        // Set the view.
        $this->setView('marketplace_home.phtml');

        // Set the title variable.
        $this->data['title'] = $this->getTitle();

        // Set the urls variables.
        //$this->data['back_url'] = $this->baseUrl . '/admin/eb/proquery';
        //$this->data['csv_url'] = $this->baseUrl . '/admin/eb/proquery/' . $arg1 . '/1';

        // Add body to data array property.
        $this->data['body'] = 'Body';

        // Set markup.
        $this->setMarkup($this->data);
    }

}
