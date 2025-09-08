#pragma once

#include "ofxJsonUtils.h"

// #define kv1(name) #name, name
// #define kv2(name, ...) kv(name), kv1(__VA_ARGS__)
// #define kv3(name, ...) kv(name), kv2(__VA_ARGS__)
// #define kv4(name, ...) kv(name), kv3(__VA_ARGS__)
// #define kv5(name, ...) kv(name), kv4(__VA_ARGS__)
// #define kv6(name, ...) kv(name), kv5(__VA_ARGS__)
// #define kv7(name, ...) kv(name), kv6(__VA_ARGS__)
// #define kv8(name, ...) kv(name), kv7(__VA_ARGS__)
// #define kv9(name, ...) kv(name), kv8(__VA_ARGS__)
// #define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME
// #define KV_COMMA_SEPARATION(...) GET_MACRO(__VA_ARGS__, kv9, kv8, kv7, kv6, kv5, kv4, kv3, kv2, kv1)(__VA_ARGS__)

// #define JSON_FUNCS(...) \
// void loadJson(const ofJson &json) {ofxJsonUtils::load(json, KV_COMMA_SEPARATION(__VA_ARGS__));}\
// ofJson toJson() const { return ofxJsonUtils::create(KV_COMMA_SEPARATION(__VA_ARGS__));}

#define EXPAND(x) x
#define kv1(name) #name, name
#define kv2(name, ...) kv(name), EXPAND(kv1(__VA_ARGS__))
#define kv3(name, ...) kv(name), EXPAND(kv2(__VA_ARGS__))
#define kv4(name, ...) kv(name), EXPAND(kv3(__VA_ARGS__))
#define kv5(name, ...) kv(name), EXPAND(kv4(__VA_ARGS__))
#define kv6(name, ...) kv(name), EXPAND(kv5(__VA_ARGS__))
#define kv7(name, ...) kv(name), EXPAND(kv6(__VA_ARGS__))
#define kv8(name, ...) kv(name), EXPAND(kv7(__VA_ARGS__))
#define kv9(name, ...) kv(name), EXPAND(kv8(__VA_ARGS__))
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME
#define KV_COMMA_SEPARATION(...) EXPAND(GET_MACRO(__VA_ARGS__, kv9, kv8, kv7, kv6, kv5, kv4, kv3, kv2, kv1)(__VA_ARGS__))

// WORKAROUNDS for MSVC below:

#define JSON_FUNCS1(a) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a); }

#define JSON_FUNCS2(a, b) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b); }

#define JSON_FUNCS3(a, b, c) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c); }

#define JSON_FUNCS4(a, b, c, d) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d); }

#define JSON_FUNCS5(a, b, c, d, e) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d, #e, e); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d, #e, e); }

#define JSON_FUNCS6(a, b, c, d, e, f) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d, #e, e, #f, f); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d, #e, e, #f, f); }

#define JSON_FUNCS7(a, b, c, d, e, f, g) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g); }

#define JSON_FUNCS8(a, b, c, d, e, f, g, h) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g, #h, h); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g, #h, h); }

#define JSON_FUNCS9(a, b, c, d, e, f, g, h, i) \
void loadJson(const ofJson &json) { ofxJsonUtils::load(json, #a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g, #h, h, #i, i); } \
ofJson toJson() const { return ofxJsonUtils::create(#a, a, #b, b, #c, c, #d, d, #e, e, #f, f, #g, g, #h, h, #i, i); }
