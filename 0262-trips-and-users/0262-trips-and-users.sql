SELECT request_at AS "Day",
ROUND((SUM(CASE WHEN status = "cancelled_by_driver" OR status = "cancelled_by_client" THEN 1 ELSE 0 END)/ COUNT(status)),2)
AS "Cancellation Rate"
FROM trips
WHERE client_id NOT IN (SELECT users_id FROM Users WHERE role = "client" AND banned = "Yes")
AND driver_id NOT IN (SELECT users_id FROM Users WHERE role = "driver" AND banned = "Yes")
AND request_at >= "2013-10-01" AND request_at <= "2013-10-03"
GROUP BY request_at