select p.nome AS nomeProjeto, dp.descricao AS depProjeto, f.nome AS nomeResponsavel, df.descricao AS depResponsavel
FROM projeto p
JOIN departamento dp ON p.codDepto = dp.codigo
JOIN funcionario f ON p.codResponsavel = f.codigo
JOIN departamento df ON f.codDepto = df.codigo
WHERE dp.codigo != df.codigo;