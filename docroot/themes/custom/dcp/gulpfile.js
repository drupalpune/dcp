var gulp = require('gulp');
// Setting pattern this way allows non gulp- plugins to be loaded as well.
var plugins = require('gulp-load-plugins')({
  pattern: '*',
  rename: {
    'node-sass-import-once': 'importOnce',
    'gulp-sass-glob': 'sassGlob',
    'run-sequence': 'runSequence',
    'gulp-clean-css': 'cleanCSS',
    'gulp-stylelint': 'gulpStylelint',

  }
});

// Used to generate relative paths for style guide output.
var path = require('path');

// These are used in the options below.
var paths = {
  styles: {
    source: 'sass/',
    destination: 'css/'
  },
  scripts: {
    source: 'js/',
    destination: 'js/'
  },
  images: {
    source: 'images/',
    destination: 'compressed-images/'
  },
};

// These are passed to each task.
var options = {
  // ----- CSS ----- //.
  css: {
    files: paths.styles.destination + '*.css',
    file: paths.styles.destination + '/style.css',
    destination: paths.styles.destination
  },
  // ----- Sass ----- //.
  sass: {
    files: paths.styles.source + '*.scss',
    file: paths.styles.source + 'style.scss',
    destination: paths.styles.destination,
    source:paths.styles.source
  },
  // ----- JS ----- //.
  js: {
    files: paths.scripts.source + '**/*.js',
    destination: paths.scripts.destination

  },
  // ----- Images ----- //.
  images: {
    files: paths.images + '**/*.{png,gif,jpg,svg}',
    destination: paths.images
  },
  // ----- eslint ----- //.
  jsLinting: {
    files: {
      theme: [
        paths.scripts + '**/*.js',
        '!' + paths.scripts + '**/*.min.js'
      ],
      gulp: [
        'gulpfile.js',
        'gulp-tasks/**/*'
      ]
    }

  },

};

// Tasks.
require('./gulp-tasks/compile-sass')(gulp, plugins, options);
require('./gulp-tasks/lint-css')(gulp, plugins, options);
require('./gulp-tasks/watch')(gulp, plugins, options);
require('./gulp-tasks/build')(gulp, plugins, options);
require('./gulp-tasks/default')(gulp, plugins, options);
