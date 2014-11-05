module Main (main) where
import Data.Maybe
import Helpers
import MathFunctions
import Text.Printf

steps_number_m  = 100
steps_number_n  = 40
steps_number_mp = 10
h_index         = 0.01
kurant_number   = 0.8
tau_index       = h_index * kurant_number

main :: IO ()
main = printResult 0 (every steps_number_mp (getLastLine 1 []))

getLastLine :: Double -> [Double] -> [Double]
getLastLine 1           []   = getLastLine 2 (getNextLine [] [alphaFunction(1 * tau_index)])
getLastLine line_number line = if line_number /= steps_number_n
                                 then getLastLine (line_number + 1) (getNextLine line [alphaFunction(line_number * tau_index)])
                                 else line

initFirstLine :: Maybe [Double] -> [Double]
initFirstLine Nothing = [phiFunction(i * h_index) | i <- [1..steps_number_m]]

getNextLine :: [Double] -> [Double] -> [Double]
getNextLine []       second_list = getNextLine (initFirstLine Nothing) second_list
getNextLine (x:[])   second_list = reverse second_list
getNextLine (x:j:xs) second_list = getNextLine (j:xs) (setTopValue x j :second_list)

setTopValue :: Double -> Double -> Double
setTopValue x j = j - kurant_number * (j - x) + tau_index * fFunction j

printResult :: Int -> [Double] -> IO ()
printResult n (x:[]) = putStrLn("X value: " ++ show(n) ++ "; U(x, t) value: " ++ printf "%.10f" x ++ ";")
printResult n (x:xs) = do
  putStrLn("X value: " ++ show(n) ++ "; U(x, t) value: " ++ printf "%.10f" x ++ ";")
  printResult (n + steps_number_mp) xs
