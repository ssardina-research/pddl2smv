(define (domain blocks)
  (:requirements :strips :typing)
  (:types block)
  (:predicates (on ?x - block ?y - block)
	       (ontable ?x - block)
	       (clear ?x - block)
	       (handempty)
	       (holding ?x - block)	       
  )
  (:action pick-up
    :parameters (?x - block)
    :precondition (and (handempty) (clear ?x) (ontable ?x))
    :effect
        (and (not (ontable ?x))
             (not (clear ?x))
             (not (handempty))
             (holding ?x))
  )
  (:action put-down
    :parameters (?x - block)
    :precondition (holding ?x)
    :effect (and (not (holding ?x)) (clear ?x) (handempty) (ontable ?x))
  )
  (:action stack
    :parameters (?x - block ?y - block)
    :precondition (and (holding ?x) (clear ?y))
    :effect 
        (and (not (holding ?x))
             (not (clear ?y))
             (clear ?x)
             (handempty)
             (on ?x ?y))
  )
  (:action unstack
    :parameters (?x - block ?y - block)
    :precondition (and (handempty) (on ?x ?y) (clear ?x))
    :effect 
        (and (holding ?x)
             (clear ?y)
             (not (clear ?x))
             (not (handempty))
             (not (on ?x ?y)))
   )
)



(define (problem basic-1)
	(:domain blocks)
	(:objects A B C D - block)
	(:init 
			(ontable A)
			(ontable B)
			(ontable C)
			(ontable D)
			(clear A)
			(clear B)
			(clear C)
			(clear D)
			(handempty)
	)
	
	(:goal !(<>((holding A)))
	)
	
	
)
