<?php
/**
 * @file
 * Views settings for Node_Clone module.
 */

/**
* Implements hook_views_data_alter()
*/
function processclone_views_data_alter(&$views_data) {
  $views_data['node']['processclone_node'] = array(
    'field' => array(
      'title' => t('Clone link'),
      'help' => t('Provide a simple link to duplicate the node.'),
      'handler' => 'views_handler_field_node_link_processclone',
    ),
  );
}
