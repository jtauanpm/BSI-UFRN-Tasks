
CREATE OR REPLACE FUNCTION ObterFuncionariosIdadeAcimaMediaDepto()
RETURNS TABLE (codigo INTEGER, nome CHARACTER VARYING)
LANGUAGE plpgsql
AS
$$
BEGIN
	RETURN QUERY 
	SELECT funcionario.codigo, funcionario.nome
	FROM funcionario
	WHERE
		idade_funcionario(funcionario.codigo) > ObterMediaIdadeDepartamento(funcionario.depto);
END;
$$;