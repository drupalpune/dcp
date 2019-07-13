/**
 * @file
 * Task: Compile: Sass.
 */

module.exports = function (gulp, plugins, options) {
  'use strict';

  gulp.task('compile:sass', function () {
    return gulp.src([
      options.sass.file
    ])
      .pipe(plugins.plumber({
        errorHandler: function (e) {
          console.log(e.messageFormatted);
          this.emit('end');
        }
      }))
      .pipe(plugins.sassGlob())
      .pipe(plugins.sass({
        errLogToConsole: true,
        outputStyle: 'expanded'
      }))
      .pipe(plugins.autoprefixer({
        browsers: ['last 4 versions'],
        grid: true,
        cascade: false
      }))
      .pipe(plugins.plumber.stop())
      .pipe(gulp.dest(options.sass.destination));
  });

  gulp.task('compile:sass-dev', function () {
    return gulp.src([
      options.sass.file
    ])
      .pipe(plugins.plumber({
        errorHandler: function (e) {
          console.log(e.messageFormatted);
          this.emit('end');
        }
      }))
      .pipe(plugins.sourcemaps.init())
      .pipe(plugins.sassGlob())
      .pipe(plugins.sass({
        errLogToConsole: true,
        outputStyle: 'expanded'
      }))
      .pipe(plugins.autoprefixer({
        browsers: ['last 2 versions'],
        cascade: false
      }))
      .pipe(plugins.sourcemaps.write())
      .pipe(plugins.plumber.stop())
      .pipe(gulp.dest(options.sass.destination));
  });
};
