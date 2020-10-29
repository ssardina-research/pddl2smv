(define (domain blocksworld)
(:requirements :strips)
(:predicates (clear ?x)
             (on-table ?x)
             (arm-empty)
             (holding ?x)
             (on ?x ?y)
)

(:action pickup
  :parameters (?ob)
  :precondition (and (clear ?ob) (on-table ?ob) (arm-empty))
  :effect (and (holding ?ob) (not (clear ?ob)) (not (on-table ?ob)) 
               (not (arm-empty))))

(:action putdown
  :parameters  (?ob)
  :precondition (and (holding ?ob))
  :effect (and (clear ?ob) (arm-empty) (on-table ?ob) 
               (not (holding ?ob))))

(:action stack
  :parameters  (?ob ?underob)
  :precondition (and (clear ?underob) (holding ?ob))
  :effect (and (arm-empty) (clear ?ob) (on ?ob ?underob)
               (not (clear ?underob)) (not (holding ?ob))))

(:action unstack
  :parameters  (?ob ?underob)
  :precondition (and (on ?ob ?underob) (clear ?ob) (arm-empty))
  :effect (and (holding ?ob) (clear ?underob)
               (not (on ?ob ?underob)) (not (clear ?ob)) (not (arm-empty))))

)
               
(define 
	(planprog BW-ring-2-blocks)
	(:domain blocksworld)
	(:objects b1 b2 b3)

	(:init 
		(arm-empty)
		(on-table b1)
		(on-table b2)
		(on-table b3)
		(clear b1)
		(clear b2)
		(clear b3)
	)
	(:initnode n0) 
	(:transitions 
		(n0 n1 (on b1 b2))
		(n1 n2 (on b2 b1))
		(n2 n0 (and (on b3 b2) (on b2 b1)))
	)
)
