// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

'use strict';

/* global describe, it */
var assert = require('assert');
var buildAddon = require('../lib/addon-builder.js').buildAddon;
var compile = require('../lib/compile.js').compile;
var path = require('path');

var BufferTest;

function bufToString(buf) {
  return String.fromCharCode.apply(null, new Uint8Array(buf));
}

function stringToArrayBuffer(str) {
  var buf = new ArrayBuffer(str.length);
  var bufView = new Uint8Array(buf);
  for (var i = 0, strLen = str.length; i < strLen; ++i) {
    bufView[i] = str.charCodeAt(i);
  }
  return buf;
}

describe('widl-nan Unit Test - Buffer', function() {
  it('Generating binding C++ code', function() {
    return compile([
      'test/buffer/buffer.widl'
    ], 'test/buffer/gen');
  });

  it('Building addon', function() {
    // building addon maybe slow
    this.timeout(100000);

    return buildAddon('test/buffer');
  });

  it('Loading addon', function() {
    var addonDir = path.join(path.dirname(__filename), 'buffer');
    var addon = require('bindings')(
        // eslint-disable-next-line camelcase
        {bindings: 'testerAddon', module_root: addonDir});

    BufferTest = addon.Buffer;
    assert.equal(typeof BufferTest, 'function');
  });

  it('Method returning an ArrayBuffer', done => {
    var bufferTest = new BufferTest();
    assert.equal(bufToString(bufferTest.getArrayBuffer()), 'hello world!');
    done();
  });

  it('Static method returning an ArrayBuffer', done => {
    assert.equal(bufToString(BufferTest.getCommonData()), 'static buffer test data');
    assert.equal(bufToString(BufferTest.getCommonData()), 'static buffer test data');
    assert.equal(bufToString(BufferTest.getCommonData()), 'static buffer test data');
    done();
  });

  it('Object property as ArrayBuffer', done => {
    var bufferTest = new BufferTest();
    assert.equal(bufToString(bufferTest.data), 'hello world!');
    done();
  });

  it('Passing ArrayBuffer as paramter', done => {
    var bufferTest = new BufferTest();
    const buffer = stringToArrayBuffer('Array buffer string test...');
    assert.equal(bufferTest.buffer2String(buffer), 'Array buffer string test...');
    done();
  });
});
