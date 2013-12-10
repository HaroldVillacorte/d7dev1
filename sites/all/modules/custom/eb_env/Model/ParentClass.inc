<?php
/**
* @file
* The ParentClass for eb_env model classes.
*/

namespace eb_env\Model;

/**
* The ParentClass model.
*/
class ParentClass
{

    /**
    * The title of the object.
    * @var string
    */
    public $title = '';

    /**
    * The result from checking the environment status.
    * @var string
    */
    public $result = '';

    /**
    * An array of related links.
    * @var array
    */
    public $links = array();

    /**
    * Explains how to interpret the result and deal with it.
    * @var string
    */
    public $description = '';

    /**
    * The location of the text files folder.
    * @var string
    */
    public $viewDir = '';

    /**
    * The ParentClass constructor.
    */
    public function __construct($title = 'Title not set.')
    {
        // Title is set in the contructor thus no title setter method.
        $this->title = (string) $title;

        // Set the text folder location.
        $dir = __DIR__ . '../../view/';
        $this->setViewDir($dir);
    }

    /**
    * Title getter.
    */
    public function getTitle()
    {
        return $this->title;
    }

    /**
    * Result setter.
    */
    public function setResult($result = '')
    {
        $this->result = (string) $result;
    }

    /**
    * Result getter.
    */
    public function getResult()
    {
        return $this->result;
    }

    /**
    * Links setter.
    */
    public function setLinks($array = array())
    {
        $this->links = (array) $array;
    }

    /**
    * Links getter.
    */
    public function getLinks()
    {
        return $this->links;
    }

    /**
    * Description setter.
    */
    public function setDescription($desc = '')
    {
        $this->description = (string) $desc;
    }

    /**
    * Body getter.
    */
    public function getDescription()
    {
        return $this->description;
    }

    /**
    * ViewDir setter.
    */
    public function setViewDir($dir)
    {
        $this->viewDir = (string) $dir;
    }

}
