<template>
    <div>
        <el-form ref="form" :model="form" class="login-box">
         <el-form-item label="账号">
             <el-input type="text" placeholder="请输入用户名" v-mode="form.name"></el-input>
         </el-form-item>
         <el-form-item label="密码">
             <el-input type="password" placeholder="请输入密码" v-mode="form.password"></el-input>
         </el-form-item>
         <el-form-item>
             <el-button type="primary" @click="onSubmit">登录</el-button>
         </el-form-item>
        </el-form>
    </div>
</template>
<script>
    export default {
        name: 'login',
        data(){
            return {
                form:{
                    name: '',
                    password:''
                }
            }
        },
        methods:{
            onSubmit() {
                alert(1)
            }
        }
    }
</script>
<style lang="scss" scoped>
    .login-box{
        width: 350px;
        margin: 150px auto;
    }
</style>