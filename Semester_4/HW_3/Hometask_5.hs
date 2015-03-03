checkOpenClose :: Char -> Char -> Bool
checkOpenClose sym1 sym2 = if ((sym1 == '(' && sym2 == ')') || (sym1 == '{' && sym2 == '}') || (sym1 == '[' && sym2 == ']')) then True else False

checkOpenBreak :: Char -> Bool
checkOpenBreak symbol = if ((symbol == '(') || (symbol == '{') || (symbol == '[')) then True else False

checkCloseBreak :: Char -> Bool
checkCloseBreak symbol = if ((symbol == ')') || (symbol == '}') || (symbol == ']')) then True else False

checkBreaks :: [Char] -> [Char] -> Bool
checkBreaks [] [] = True
checkBreaks [] _ = False
checkBreaks (x:xs) acc = if (checkOpenBreak x) then (checkBreaks xs (x:acc)) else
							if (checkCloseBreak x) then 
								if (acc == []) then False else 
									if (checkOpenClose (head acc) x) then (checkBreaks xs (tail acc)) else False 
							else (checkBreaks xs acc)

checkLine :: [Char] -> Bool
checkLine xs = checkBreaks xs []
