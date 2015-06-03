<?php
// Plugin definition
$plugin = array(
  'title' => t('Orion'),
  'icon' => 'orion.png',
  'category' => t('COD'),
  'theme' => 'orion',
  'css' => '../../../css/panels/orion/orion.css',
  'regions' => array(
    'banner' => t('Banner'),
    'left_header' => t('Left Header'),
    'right_header' => t('Right Header'),
    'preface' => t('Preface'),
    'left_content' => t('Left Content'),
    'right_content' => t('Right Content'),
    'footer' => t('Footer'),
  ),
);
