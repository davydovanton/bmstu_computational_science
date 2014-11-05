module Helpers (every) where

every :: Int -> [Double] -> [Double]
every n xs = case drop (n-1) xs of
              (y:ys) -> y : every n ys
              [] -> []
