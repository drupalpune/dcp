<?php
/**
 * @file
 * cod_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cod_news_taxonomy_default_vocabularies() {
  return array(
    'news_tags' => array(
      'name' => 'News Tags',
      'machine_name' => 'news_tags',
      'description' => 'Tags for news items',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
