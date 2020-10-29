(define (problem b2)
  (:domain blocks)
  (:objects A B C D - block)
  (:init
     (and (holding A) (ontable B) (ontable C) (ontable D))
  )
  (:goal
     (and (ontable A)
          (holding D)
     )
  )
)
