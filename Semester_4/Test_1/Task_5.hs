data ToRead = Book {name :: String, author :: String, cost :: Int}
			| Magazine {name :: String, year :: Int, number :: Int, cost :: Int}	

sumCost :: [ToRead] -> Int
sumCost [] = 0
sumCost (x:xs) = (cost x) + (sumCost xs)