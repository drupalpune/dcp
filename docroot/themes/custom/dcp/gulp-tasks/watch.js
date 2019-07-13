/**
 * @file
 * Task: Watch.
 */
module.exports = function (gulp, plugins, options) {
  'use strict';
  gulp.task('watch', function (done) {
    return gulp.watch(options.sass.source, gulp.series('compile:sass-dev'));
  });
};
