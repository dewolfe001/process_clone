<?php

/**
 * @file Node clone rules functions
 */

/**
 * Implementation of hook_rules_event_info.
 */
function processclone_rules_event_info() {
  // Let rules know about the node clone event.
  $items = array(
    'processclone_node' => array(
      'label' => t('After cloning a node'),
      'group' => t('Node'),
      'variables' => array(
        'cloned_node' => array('type' => 'node', 'label' => t('The cloned node')),
        'original_node' => array('type' => 'node', 'label' => t('The original node')),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_rules_action_info().
 */
function processclone_rules_action_info() {
  $actions = array(
    'processclone_action_node_processclone' => array(
      'label' => t('Clone a node'),
      'group' => t('Node'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node to clone'),
        ),
      ),
      'provides' => array(
        'clone' => array(
          'type' => 'node',
          'label' => t('Cloned node'),
        ),
      ),
    ),
  );
  return $actions;
}

/**
 * Action callback for cloning a node.
 * @param $node
 *   The node to clone.
 */
function processclone_action_node_processclone($node) {
  include_once drupal_get_path('module', 'processclone') . '/processclone.pages.inc';
  $new_nid = processclone_node_save($node->nid);
  $new_node = entity_load_single('node', $new_nid);
  return array(
    'clone' => $new_node,
  );
}
