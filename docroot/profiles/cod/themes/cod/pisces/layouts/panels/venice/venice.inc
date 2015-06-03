<?php
// Plugin definition
$plugin = array(
  'title' => t('Venice'),
  'icon' => 'venice.png',
  'category' => t('Panelitist'),
  'theme' => 'venice',
  'css' => '../../../css/panels/venice/venice.css',
  'regions' => array(
    'banner' => t('Banner'),
    'overlay' => t('Overlay Content'),
    'headercontent' => t('HeaderContent'),
    'column1' => t('First Column'),
    'column2' => t('Second Column'),
    'footer_column_1' => t('Footer Column 1'),
    'footer_column_2' => t('Footer Column 2'),
  ),
);
