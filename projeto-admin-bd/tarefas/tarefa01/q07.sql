CREATE VIEW funcPorDepto_view AS
SELECT f.codDepto, count(f.codigo) AS quantidade
FROM funcionario f
GROUP BY f.codDepto;

SELECT g.nome AS gerente, d.descricao AS departamento, fd.quantidade AS funcionarios
FROM funcPorDepto_view fd LEFT JOIN departamento d ON d.codigo = fd.codDepto
LEFT JOIN funcionario g ON d.codGerente = g.codigo;