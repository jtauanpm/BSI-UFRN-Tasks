CREATE VIEW atividadesPorProjeto_View AS
SELECT ap.codProjeto, COUNT(DISTINCT ap.codAtividade) AS qtdeAtividades, COUNT(DISTINCT a.codResponsavel) AS qtdeResponsaveis
FROM atividade_projeto ap
JOIN atividade a ON a.codigo = ap.codAtividade
GROUP BY ap.codProjeto;

CREATE VIEW projetoResponsavel_View AS
SELECT p.nome AS nomeProjeto, d.descricao AS nome_departamento, f.nome AS nomeResponsavel, apc.qtdeAtividades, apc.qtdeResponsaveis
FROM projeto p
JOIN departamento d ON p.codDepto = d.codigo
JOIN funcionario f ON p.codResponsavel = f.codigo
LEFT JOIN atividadesPorProjeto_View apc ON p.codigo = apc.codProjeto;

SELECT pr.nomeProjeto, pr.nomeResponsavel, pr.qtdeAtividades, pr.qtdeResponsaveis
FROM projetoResponsavel_View pr;