<?php
/**
* @file
* Parent controller for the eb_proquery module.
*/

namespace eb_proquery\Controller;

class ParentController
{

    /**
    * The title.
    * @var string
    */
    protected $title;

    /**
    * The data array.
    * @var array
    */
    protected $data = array();

    /**
    * The page markup.
    * @var string
    */
    protected $markup;

    /**
    * The view directory.
    * @var string
    */
    protected $viewDir;

    /**
    * The view file.
    * @var string
    */
    protected $view;

    /**
    * The global base url.
    * @var string
    */
    protected $baseUrl;

    /**
    * The ParentController contructor.
    * @param string $title The Page title.
    */
    public function __construct($title = 'Title not set')
    {
        // Set the base url.
        global $base_url;
        $this->setBaseUrl($base_url);

        // Set the title.
        $this->setTitle($title);
        $this->data['title'] = $this->title;

        // Set the view directory.
        $this->setViewDir(__DIR__ . '../../view/');
    }

    /**
    * The $title setter.
    * @param string The title string.
    */
    public function setTitle($title = 'Title not set')
    {
        $this->title = (string) $title;
    }

    /**
    * The $title getter.
    * @return string $title The page title.
    */
    public function getTitle()
    {
        return $this->title;
    }

    /**
    * The $markup setter.
    * @param string $markup The markup string.
    */
    public function setMarkup($data = array())
    {
        $view = t(file_get_contents($this->view));
        foreach ((array) $data as $key => $value) {
            $view = str_replace('<% ' . $key . ' %>', $value, $view);
        }
        $this->markup = $view;
    }

    /**
    * The $markup getter.
    * @return array The page markup.
    */
    public function getMarkup()
    {
        return array(
            '#markup' => $this->markup,
        );
    }

    /**
    * The $viewDir setter.
    * @param string $dir The view directory path.
    */
    public function setViewDir($dir = '')
    {
        $this->viewDir = (string) $dir;
    }

    /**
    * The $view setter.
    * @param string $file The view file name.
    */
    public function setView($view = '')
    {
        $this->view = $this->viewDir . $view;
    }

    /**
    * The $baseUrl setter.
    * @param string The base url.
    */
    public function setBaseUrl($baseUrl = '')
    {
        $this->baseUrl = $baseUrl;
    }

}
