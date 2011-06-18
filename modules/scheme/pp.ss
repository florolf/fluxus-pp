;; [ Copyright (C) 2008 Dave Griffiths : GPLv2 see LICENCE ]

;; StartSectionDoc-en
;; scheme-utils
;; High level fluxus commands written in Scheme.
;; Example:
;; EndSectionDoc 

#lang racket/base
(require "fluxus-modules.ss")
(provide pp-shader-identity)

;; StartFunctionDoc-en
;; build-circle-points num-points radius
;; Returns: primitive-id
;; Description:
;; Returns a list of vectors describing a circle. 
;; Useful for generating circles for the extrusion generator.
;; Example:  
;; (clear)
;; (build-extrusion 
;;     (build-circle-points 20 0.3)
;;     (list
;;         (vector 0 0 0)
;;         (vector 0 1 2)
;;         (vector 0 -1 4)
;;         (vector 0 0 6))
;;     (list 0 1 1 0) 1 (vector 0 1 0))
;; EndFunctionDoc 

(define (pp-shader-identity)
  (pp-shader "
uniform sampler2D tex;
varying vec2 tc;
void main() {
  gl_FragColor = texture2D(tex,tc);
  }"))
