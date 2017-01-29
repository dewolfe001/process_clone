<?php
/**
 * @file
 * Views field handler for Node_Clone module.
 */

/**
* Field handler to present a process duplication link in a view.
*
* Closely modeled after views/modules/node/views_handler_field_node_link_edit.inc
*/
class views_handler_field_node_link_processclone extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($node, $values) {

    if (!processclone_access_cloning($node)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "node/{$node->nid}/processclone/" . processclone_get_token($node->nid);
    $method = variable_get('clone_method', 'prepopulate');
    $destination = drupal_get_destination();
    if ($method == 'prepopulate') {
      $this->options['alter']['query'] = $destination;
    }
    elseif (!empty($destination['destination'])) {
      $this->options['alter']['query']['process-clone-destination'] = $destination['destination'];
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('clone');
    return $text;
  }
}
