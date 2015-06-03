<?php
// Plugin definition
$plugin = array(
  'title' => t('Hydra'),
  'icon' => 'hydra.png',
  'category' => t('COD'),
  'theme' => 'hydra',
  'css' => '../../../css/panels/hydra/hydra.css',
  'regions' => array(
    'preface' => t('Preface'),
    'left_content' => t('Left Content'),
    'top_right_content' => t('Top Right Content'),
    'bottom_right_content' => t('Bottom Right Content'),
    'footer' => t('Footer'),
  ),
);
