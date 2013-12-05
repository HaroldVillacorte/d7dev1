<?php
/**
* @file
* The parent_class for eb_env model classes.
*/

namespace eb_env\model;

/**
* The parent_class.
*/
class parent_class
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
    public $text_dir = '';
    
    /**
    * The parent_class constructor.
    */
    public function __construct($title = 'Title not set.')
    {
        // Title is set in the contructor thus no title setter method.
        $this->title = (string) $title;
        
        // Set the text folder location.
        $dir = __DIR__ . '../../text/';
        $this->set_text_dir($dir);
    }
    
    /**
    * Title getter.
    */
    public function get_title()
    {
        return $this->title;
    }
    
    /**
    * Result setter.
    */
    public function set_result($result = '')
    {
        $this->result = (string) $result;
    } 
    
    /**
    * Result getter.
    */
    public function get_result()
    {
        return $this->result;
    }
    
    /**
    * Links setter.
    */
    public function set_links($array = array())
    {
        $this->links = (array) $array;
    }
    
    /**
    * Links getter.
    */
    public function get_links()
    {
        return $this->links;
    }
    
    /**
    * Body setter.
    */
    public function set_description($body = '')
    {
        $this->description = (string) $body;
    } 
    
    /**
    * Body getter.
    */
    public function get_description()
    {
        return $this->description;
    }
    
    /**
    * Text_dir setter.
    */
    public function set_text_dir($dir)
    {
        $this->text_dir = (string) $dir;
    }

}
