// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

'use strict';

/* global describe, it */
var assert = require('assert');
var buildAddon = require('../lib/addon-builder.js').buildAddon;
var compile = require('../lib/compile.js').compile;
var path = require('path');

var FakeImage = null;

describe('widl-nan Unit Test - sequence<T> as Array', function() {
  it('Generating binding C++ code', function() {
    return compile('test/typedarray/typedarray.widl', 'test/typedarray/gen');
  });

  it('Building addon', function() {
    // building addon maybe slow
    this.timeout(100000);

    return buildAddon('test/typedarray');
  });

  it('Loading addon', function() {
    var addonDir = path.join(path.dirname(__filename), 'typedarray');
    var addon = require('bindings')(
        // eslint-disable-next-line camelcase
        {bindings: 'widlNanAddon', module_root: addonDir});
    FakeImage = addon.FakeImage;
    assert.equal(typeof FakeImage, 'function');
  });

  it('Test TypedArray as property', done => {
    done();
  });
});
