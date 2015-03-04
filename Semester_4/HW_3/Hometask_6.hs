--func f g l = filter f (map g l)
--func f g l = filter f ((map g) l)
--func f g l = ((filter f) . (map g)) l
--func f g = ((filter f) . (map g))
--func f g = (filter f) . map g
func f = (filter f) . map