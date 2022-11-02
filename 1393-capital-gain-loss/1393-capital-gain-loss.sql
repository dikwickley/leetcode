# Write your MySQL query statement below
# UPDATE Stocks SET price = -1*price WHERE operation = 'SELL';
# SELECT * FROM Stocks;

SELECT stock_name, SUM(
    CASE
        WHEN operation = 'Buy' THEN -price
        ELSE price
    END
) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name