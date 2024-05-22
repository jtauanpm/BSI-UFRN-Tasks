-- Faça uma consulta que selecione o nome, o salário e o departamento dos funcionários que não são gerentes, 
-- ordenando pelo Código do Departamento.


SELECT f.nome, f.salario, f.codDepto
FROM funcionario f
WHERE f.codigo NOT IN (
  SELECT codGerente
  FROM departamento
  WHERE codGerente IS NOT NULL
)
ORDER BY f.codDepto;