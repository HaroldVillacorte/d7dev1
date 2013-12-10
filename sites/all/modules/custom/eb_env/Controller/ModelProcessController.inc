<?php
/**
* @file
* Gets the model classes and generates the output array.
*/

namespace eb_env\Controller;

$modulePath = drupal_get_path('module', 'eb_env');
require_once $modulePath . '/Model/Server.inc';
require_once $modulePath . '/Model/ZendOpcache.inc';
require_once $modulePath . '/Model/SmartIp.inc';

/**
* The ModelProcess Controller.
*/
class ModelProcessController
{

    /**
    * Generates the output array.
    */
    public function getOutput()
    {
        // Instatiate the child model classes.
        $server = new \eb_env\Model\Server();
        $zendOpcache = new \eb_env\Model\ZendOpcache();
        $smartIp = new \eb_env\Model\SmartIp();

        // Generate the output array and return.
        return array(

            // Server.
            array(
                'title' => $server->getTitle(),
                'result' => $server->getResult(),
                'links' => $server->getLinks(),
                'description' => $server->getDescription(),
            ),

            // ZendOpcache
            array(
                'title' => $zendOpcache->getTitle(),
                'result' => $zendOpcache->getResult(),
                'links' => $zendOpcache->getLinks(),
                'description' => $zendOpcache->getDescription(),
            ),

            // SmartIp
            array(
                'title' => $smartIp->getTitle(),
                'result' => $smartIp->getResult(),
                'links' => $smartIp->getLinks(),
                'description' => $smartIp->getDescription(),
            ),
        );
    }

}
