(load "rules.scm")

(define (make-matrix n m a)
  (let outter ((i (- n 1)) (result '()))
    (if (= i (- 1))
        result
        (outter ( - i 1) 
                (cons
                 (let inner ((j (- m 1)) (row '()))
                   (if (= j (- 1))
                       row
                       (inner (- j 1) (cons (ստանալ (ստանալ  a i) j) row))))
                 result)))))
                 
(define a (list (list 1 2 3 4) (list 2 3 4 5) (list 3 4 5 6)))      
(define matrix (make-matrix  3 4 a))
(display matrix)
(display (ստանալ (ստանալ  matrix 1) 2))
;(define set_item





(define (set_item  matrix k q  val)
	(define n (length matrix)) 
	(define m (length (ստանալ matrix 0))) 
	(let outter ((i (- n 1)) (result '()))
    	(if (= i (- 1))
      	  	result
        	(outter ( - i 1) 
                (cons
                 (let inner ((j (- m 1)) (row '()))
                   (if (= j (- 1))
                       row
                       (inner (- j 1) (cons (if (և (= i k) (= j q)) val (ստանալ (ստանալ  matrix i) j)) row))))
                 	result)))))


 (define (set matrix i j val)
	(set! matrix (set_item matrix i j val))
	(display matrix)
    ) 
;(display (set_item matrix 1 2 0 ))
(set matrix 1 2 0 )
(display matrix)
