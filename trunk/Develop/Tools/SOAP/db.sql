USE SoulHuntMonitor
go

-- 리플레이 로그
IF OBJECT_ID('ReplayLog') IS NOT NULL 
 DROP TABLE ReplayLog;
GO

CREATE TABLE ReplayLog
(
LID INT NOT NULL IDENTITY PRIMARY KEY CLUSTERED
, Computer VARCHAR(32)
, fps INT
, LoadingTime INT
, RegDate DATETIME NOT NULL	
);
go


-- 피드백
IF OBJECT_ID('Feedback') IS NOT NULL 
 DROP TABLE Feedback;
GO

CREATE TABLE Feedback
(
FID INT NOT NULL IDENTITY PRIMARY KEY CLUSTERED
, UserID VARCHAR(32)
, Name VARCHAR(32)
, Field INT
, pos VARCHAR(32)
, dir VARCHAR(32)
, Comment TEXT
, Tag VARCHAR(64)
, RegDate DATETIME NOT NULL	
);
go
